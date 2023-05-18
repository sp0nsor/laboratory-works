import Animal from './Animal';

class Veterinarian {
  treatAnimal(animal: Animal): void {
    console.log('Еда животного: ' + animal.food);
    console.log('Местоположение животного: ' + animal.location);
  }
}

export default Veterinarian;