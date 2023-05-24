function CheckPangram(words, date) {
    for (var i = 0; i < words.length; i++) {
        if (words[i] == " ") {
            i++;
        }
        if (date.includes(words[i])) {
            //console.log(date[i], " - ", words[i]);
        }
        else {
            return false;
            break;
        }
    }
    return true;
}
var date = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
var words = "А ещё хорошо бы уметь всем на зависть чётко и наглядно писать буквы и цифры";
console.log(CheckPangram(words, date));
