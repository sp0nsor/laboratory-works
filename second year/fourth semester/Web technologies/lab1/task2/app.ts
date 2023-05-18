import Animal from './Animal';
import Dog from './Dog';
import Cat from './Cat';
import Horse from './Horse';
import Veterinarian from './Veterinarian';

const animals: Animal[] = [
  new Dog('мясо', 'дом', 'овчарка'),
  new Cat('рыба', 'дом', 'черный'),
  new Horse('сено', 'стойло', 'тяжеловоз')
];

const veterinarian = new Veterinarian();

for (const animal of animals) {
  veterinarian.treatAnimal(animal);
}