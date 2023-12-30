const app = require("./src/app");
const express = require('express');
const swaggerUi = require('swagger-ui-express');
const swaggerSpec = require('./swagger');

const app = express();

app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerSpec));

const APP_PORT = 3000;

app.listen(APP_PORT, () => {
  console.log(`App listening at ${APP_PORT}`);
});
