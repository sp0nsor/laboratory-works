const { Sequelize, DataTypes } = require('sequelize');
const Joi = require('joi');

const readerSchema = Joi.object({
  name: Joi.string().required().messages({
    'any.required': 'Please provide a name',
    'string.empty': 'Name field cannot be empty',
  }),
  email: Joi.string().email().required().messages({
    'any.required': 'Please provide an email',
    'string.email': 'Please provide a valid email',
    'string.empty': 'Email field cannot be empty',
  }),
  profilePicture: Joi.string().allow(null),
});

module.exports = (connection, DataTypes) => {
  const schema = {
    name: {
      type: DataTypes.STRING,
      allowNull: false,
      validate: {
        notNull: {
          args: [true],
          msg: 'Please provide a name',
        },
        notEmpty: {
          args: [true],
          msg: 'Name field cannot be empty',
        },
      },
    },
    email: {
      type: DataTypes.STRING,
      unique: true,
      allowNull: false,
      validate: {
        notNull: {
          args: [true],
          msg: 'Please provide an email',
        },
        notEmpty: {
          args: [true],
          msg: 'Email field cannot be empty',
        },
        isEmail: {
          args: [true],
          msg: 'Please provide a valid email',
        },
      },
    },
    profilePicture: {
      type: DataTypes.STRING,
      allowNull: true,
    },
  };

  const ReaderModel = connection.define('Reader', schema, {
    timestamps: false,
  });

  return ReaderModel;
};
