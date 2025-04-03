
const fs = require('fs');



const data = {
    name: "derrick",
    age: 12,
    profession: "painter"
};

const jsonData = JSON.stringify(data, null, 2); // null and 2 are used for pretty-printing


fs.appendFile('data.json', jsonData, (err) => {
    if (err) {
        console.error("Error writing file:", err);
        return;
    }
    console.log("File has been written successfully!");
});

fs.readFile(`data.json`, 'utf-8', (err, data) => {
    if (err) {
        console.error("Error reading file:", err);
        return;
    }
    const jsonData = JSON.parse(data);
    console.log(jsonData);

})
