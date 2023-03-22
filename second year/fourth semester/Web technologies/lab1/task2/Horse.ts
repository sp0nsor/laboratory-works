import Animal from './Animal';

class Horse extends Animal {
  breed: string;

  constructor(food: string, location: string, breed: string) {
    super(food, location);
    this.breed = breed;
  }

  makeNoise(): void {
    console.log('Лошадь ржет');
  }

  eat(): void {
    console.log('Лошадь ест ' + this.food);
  }

  gallop(): void {
    console.log('Лошадь галопирует');
  }
}

export default Horse;