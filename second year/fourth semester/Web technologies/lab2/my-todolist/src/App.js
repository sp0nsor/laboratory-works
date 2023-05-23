import React, { useState, useEffect } from 'react';
import { Route, Routes } from 'react-router-dom';
import { BrowserRouter as Router } from 'react-router-dom';
import { Link } from 'react-router-dom';
import axios from 'axios';
function App() {
  const [todos, setTodos] = useState([]);
  const [newTodo, setNewTodo] = useState('');

  useEffect(() => {
    axios.get('http://localhost:3000/todos')
      .then(res => {
        setTodos(res.data);
      })
      .catch(err => console.log(err));
  }, []);

  const handleInputChange = (event) => {
    setNewTodo(event.target.value);
  }

  const handleSubmit = (event) => {
    event.preventDefault();
    axios.post('http://localhost:3000/todos', { title: newTodo })
      .then(res => {
        console.log(res.data);
        setTodos([...todos, { title: newTodo }]);
        setNewTodo('');
      })
      .catch(err => console.log(err));
  }

  return (
    <Router>
      <div>
        <nav>
          <ul>
            <li>
              <Link to="/">Home</Link>
            </li>
            <li>
              <Link to="/add">Add Todo</Link>
            </li>
          </ul>
        </nav>
      <Routes>
        <Route exact path="/" element={<Home/>}>
          <div>
            <h2>Todos</h2>
            <ul>
              {todos.map((todo, index) => (
                <li key={index}>{todo.title}</li>
              ))}
            </ul>
          </div>
        </Route></Routes><Routes>
        <Route path="/add" element={<><AddTodo addTodo={addTodo}/>}>
          <div>
            <h2>Add Todo</h2>
            <form onSubmit={handleSubmit}>
              <input type="text" value={newTodo} onChange={handleInputChange} />
              <button type="submit">Add</button>
            </form>
          </div>
        </Route></Routes>
      </div>
    </Router>
  );
}
export default App;