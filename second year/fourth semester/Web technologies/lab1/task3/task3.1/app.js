var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
function validateNumber(target, propertyKey, descriptor) {
    console.log("target", target);
    console.log("propertyKey", propertyKey);
    console.log("descriptor", descriptor);
    var originalMethod = descriptor.value;
    descriptor.value = function (value) {
        if (typeof value !== 'number') {
            throw new Error("Invalid type for ".concat(propertyKey, ". Expected number, but got ").concat(typeof value, "."));
        }
        return originalMethod.call(this, value);
    };
}
function checkNonNegative(target, propertyKey, descriptor) {
    console.log("target", target);
    console.log("propertyKey", propertyKey);
    console.log("descriptor", descriptor);
    var originalMethod = descriptor.value;
    descriptor.value = function (value) {
        if (value < 0) {
            throw new Error("Invalid argument for ".concat(propertyKey, ". Expected non-negative number, but got ").concat(value, "."));
        }
        return originalMethod.call(this, value);
    };
}
var Integer = /** @class */ (function () {
    function Integer(value) {
        this._value = value;
    }
    Object.defineProperty(Integer.prototype, "value", {
        get: function () {
            return this._value;
        },
        set: function (value) {
            this._value = value;
        },
        enumerable: false,
        configurable: true
    });
    Integer.prototype.sqrt = function () {
        return Math.sqrt(this._value);
    };
    __decorate([
        checkNonNegative
    ], Integer.prototype, "sqrt");
    return Integer;
}());
