function CheckPangram(words: string, date: string){
    for (let i: number = 0; i < words.length; i++){
        if (words[i] == " "){
            i++;
        }
        if (date.includes(words[i])){
            console.log(date[i], " - ", words[i])
        }
        else{
            return false;
            break;
        }
    }
    return true;
}

let date: string = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
let words: string = "А ещё хорошо бы уметь всем на зависть чётко и наглядно писать буквы и цифры";
console.log(CheckPangram(words, date));