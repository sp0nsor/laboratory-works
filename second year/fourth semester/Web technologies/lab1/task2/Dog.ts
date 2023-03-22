import Animal from './Animal';

class Dog extends Animal {
  breed: string;

  constructor(food: string, location: string, breed: string) {
    super(food, location);
    this.breed = breed;
  }

  makeNoise(): void {
    console.log('Собака лает');
  }

  eat(): void {
    console.log('Собака ест ' + this.food);
  }

  bark(): void {
    console.log('Собака лает');
  }
}

export default Dog;