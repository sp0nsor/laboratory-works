function validateNumber(target: any, propertyKey: string, descriptor: PropertyDescriptor) {
  console.log("target", target);
  console.log("propertyKey", propertyKey);
  console.log("descriptor", descriptor);
    const originalMethod = descriptor.value;
    descriptor.value = function(value: number) { 
      if (typeof value !== 'number') {
        throw new Error(`Invalid type for ${propertyKey}. Expected number, but got ${typeof value}.`);
      }
      return originalMethod.call(this, value);
    };
  }
  
  function checkNonNegative(target: any, propertyKey: string, descriptor: PropertyDescriptor) {
    console.log("target", target);
  console.log("propertyKey", propertyKey);
  console.log("descriptor", descriptor);
    const originalMethod = descriptor.value;
    
    descriptor.value = function(value: number) { 
      if (value < 0) {
        throw new Error(`Invalid argument for ${propertyKey}. Expected non-negative number, but got ${value}.`);
      }
      return originalMethod.call(this, value);
    };
  }
  
  class Integer {
    private _value: number;
  
    constructor(value: number) {
      this._value = value;
    }
  
    public set value(value: number) {
      this._value = value;
    }
  
    public get value(): number {
      return this._value;
    }
  
    @checkNonNegative
    public sqrt(): number {
      return Math.sqrt(this._value);
    }
  }