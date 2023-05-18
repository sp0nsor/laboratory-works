function getDayOfWeek(date: Date): string {
    const daysOfWeek: string[] = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
    const dayIndex: number = date.getDay();
    return daysOfWeek[dayIndex];
  }
  
  function addDays(date: Date, days: number): Date {
    const result: Date = new Date(date);
    result.setDate(result.getDate() + days);
    return result;
  }
  
  const date: Date = new Date('2023-03-23'); // Задаем начальную дату
  const K: number = 5; // Задаем количество дней, на которое нужно сдвинуть дату
  const newDate: Date = addDays(date, K); // Сдвигаем дату на K дней
  const dayOfWeek: string = getDayOfWeek(newDate); // Определяем день недели
  console.log(dayOfWeek); // Выводим результат в консоль