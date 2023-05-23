const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');

const app = express();

app.use(bodyParser.json());
app.use(cors());

const todos = [];

app.get('/todos', (req, res) => {
  res.send(todos);
});

app.post('/todos', (req, res) => {
  const newTodo = req.body;
  todos.push(newTodo);
  res.send('Todo added successfully');
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});