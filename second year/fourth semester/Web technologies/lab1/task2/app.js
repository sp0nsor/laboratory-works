"use strict";
exports.__esModule = true;
var Dog_1 = require("./Dog");
var Cat_1 = require("./Cat");
var Horse_1 = require("./Horse");
var Veterinarian_1 = require("./Veterinarian");
var animals = [
    new Dog_1["default"]('мясо', 'дом', 'овчарка'),
    new Cat_1["default"]('рыба', 'дом', 'черный'),
    new Horse_1["default"]('сено', 'стойло', 'тяжеловоз')
];
var veterinarian = new Veterinarian_1["default"]();
for (var _i = 0, animals_1 = animals; _i < animals_1.length; _i++) {
    var animal = animals_1[_i];
    veterinarian.treatAnimal(animal);
}
