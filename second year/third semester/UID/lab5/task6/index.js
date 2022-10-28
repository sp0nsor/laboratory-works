function data_sort(dates){
    dates.sort().reverse();
    return dates;
}

dates = ['2003.12.14','2005.06.03','2004.07.29', "2004.06.29"];
console.log(data_sort(dates));