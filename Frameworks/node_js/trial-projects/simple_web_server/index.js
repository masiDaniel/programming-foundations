const express = require('express')
const bodyParser = require('body-parser')

const app = express();
app.use(bodyParser.json());




//get request handler 
app.get('/users', (req, res)=> {
    //logic to handle the get request for retrieveing users
    res.send('GET /users')
});

//POST request handler 
app.post('/users', (req, res)=> {
    //logic to handle the Post request for creating users
    res.status(201).send("user created succesfully");
});



//PUT request handler 
app.put('/users/:id', (req, res)=> {
    const userId = req.params.id; // where are the params defined?
    //logic to handle the get request for updating a user 
    res.send(`PUT /users/${userId}`);
});


// DELETE request handler
app.delete('/users/:id', (req, res) => {
  const userId = req.params.id;
  // Logic to handle the DELETE request for deleting a user with the specified ID
  res.send(`DELETE /users/${userId}`);
});

const port = 3000;
app.listen(port, () => {
    console.log(`server is running on port ${port}`);

})