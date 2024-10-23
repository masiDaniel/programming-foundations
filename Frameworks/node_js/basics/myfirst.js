//this code tells the computer to write hello world if anyone tries to access your computer on port 8080
var http = require('http');

http.createServer(function (req, res) {
    res.writeHead(200, {'Content-type': 'text/html'});
    res.end('hello world');
}).listen(8080);

