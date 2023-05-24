"use strict";
exports.__esModule = true;
var Veterinarian = /** @class */ (function () {
    function Veterinarian() {
    }
    Veterinarian.prototype.treatAnimal = function (animal) {
        console.log('Еда животного: ' + animal.food);
        console.log('Местоположение животного: ' + animal.location);
    };
    return Veterinarian;
}());
exports["default"] = Veterinarian;
