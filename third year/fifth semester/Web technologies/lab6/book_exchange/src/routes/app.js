const express = require("express");
const cors = require('cors');

const readerRouter = require("./reader");
const bookRouter = require("./book");
const authorRouter = require("./author");
const genreRouter = require("./genre");

const app = express();

app.use(express.json());
app.use(cors());

app.use("/readers", readerRouter);
app.use("/books", bookRouter);
app.use("/authors", authorRouter);
app.use("/genres", genreRouter);

module.exports = app;
