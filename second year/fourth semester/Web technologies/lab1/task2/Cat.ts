import Animal from './Animal';

class Cat extends Animal {
  color: string;

  constructor(food: string, location: string, color: string) {
    super(food, location);
    this.color = color;
  }

  makeNoise(): void {
    console.log('Кошка мяукает');
  }

  eat(): void {
    console.log('Кошка ест ' + this.food);
  }

  purr(): void {
    console.log('Кошка мурлычет');
  }
}

export default Cat;