function getDayOfWeek(date) {
    var daysOfWeek = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
    var dayIndex = date.getDay();
    return daysOfWeek[dayIndex];
}
function addDays(date, days) {
    var result = new Date(date);
    result.setDate(result.getDate() + days);
    return result;
}
var date = new Date('2023-03-23'); // Задаем начальную дату
var K = 5; // Задаем количество дней, на которое нужно сдвинуть дату
var newDate = addDays(date, K); // Сдвигаем дату на K дней
var dayOfWeek = getDayOfWeek(newDate); // Определяем день недели
console.log(dayOfWeek); // Выводим результат в консоль
