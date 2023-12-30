const swaggerJSDoc = require('swagger-jsdoc');

const options = {
  definition: {
    openapi: '3.0.0',
    info: {
      title: 'Your API',
      version: '1.0.0',
      description: 'API documentation',
    },
  },
  apis: ['./routes/app.js'],
};

const swaggerSpec = swaggerJSDoc(options);

module.exports = swaggerSpec;
