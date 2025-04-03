const data = require("/home/azte-c/CodeByMasi/programming-foundations/Frameworks/node_js/trial-projects/calculator_cli/data.json")
// Get command-line arguments
const args = process.argv.slice(2);

if (args.length < 3) {
    console.log("Usage: node calculator.js <num1> <operator> <num2>");
    console.log("Example: node calculator.js 5 + 3");
    process.exit(1); // Exit if not enough arguments
}


// Extract values
const num1 = parseFloat(args[0]);
const operator = args[1];
const num2 = parseFloat(args[2]);


// Function to perform calculations
function calculate(num1, operator, num2) {
    if (isNaN(num1) || isNaN(num2)) {
        return "Error: Both inputs must be numbers.";
    }

    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
        case 'x':
            return num1 * num2;
        case '/':
            return num2 !== 0 ? num1 / num2 : "Error: Division by zero!";
        default:
            return "Error: Unsupported operator. Use +, -, *, or /.";
    }
}

function read_data(data){
    console.log(`this is the data: ${JSON.stringify(data, null, 2)}`);

}


// Perform the calculation and print result
const result = calculate(num1, operator, num2);
console.log(`Result: ${num1} ${operator} ${num2} = ${result}`);
read_data(data);