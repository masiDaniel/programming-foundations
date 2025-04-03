const fs = require('fs');

const args = process.argv.slice(2);

if (args.length < 2) {
    console.log("Usage: node script.js <operation> <file>");
    console.log("Example: node script.js read tasks.txt");
    process.exit(1);
}

const operation = args[0];
const file = args[1];

function handleFileOperation(operation, file) {
    switch (operation) {
        case "read":
            // Check if file exists before reading
            if (!fs.existsSync(file)) {
                console.log(`File "${file}" not found. Creating an empty file...`);
                fs.writeFileSync(file, ""); // Creates an empty file
            }

            fs.readFile(file, "utf8", (err, data) => {
                if (err) {
                    console.error("Error reading file:", err.message);
                    return;
                }
                console.log("File Contents:\n", data || "File is empty.");
            });
            break;

        case "write":
            const text = args.slice(2).join(" ");
            if (!text) {
                console.log("Error: No text provided to write.");
                return;
            }
            fs.writeFile(file, text, (err) => {
                if (err) {
                    console.error("Error writing to file:", err.message);
                    return;
                }
                console.log(`Successfully wrote to ${file}`);
            });
            break;

        case "append":
            const appendText = args.slice(2).join(" ");
            if (!appendText) {
                console.log("Error: No text provided to append.");
                return;
            }
            fs.appendFile(file, appendText + "\n", (err) => {
                if (err) {
                    console.error("Error appending to file:", err.message);
                    return;
                }
                console.log(`Successfully appended to ${file}`);
            });
            break;

        default:
            console.log("Error: Unsupported operation. Use 'read', 'write', or 'append'.");
    }
}

handleFileOperation(operation, file);
