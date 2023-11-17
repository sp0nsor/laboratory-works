import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Home from './pages/Home';
import AddBook from './pages/AddBook';
import BuyBook from './pages/BuyBook';
import SwapBook from './pages/SwapBook';

function App() {
  return (
    <Router>
      <Routes>
        <Route path='/' element={<Home />} />
        <Route path='/add' element={<AddBook />} />
        <Route path='/buy' element={<BuyBook />} />
        <Route path='/swap' element={<SwapBook />} />
      </Routes>
    </Router>
  );
}

export default App;
