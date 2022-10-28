function sort_array(array){
    odd_array = [];
    even_array = [];
    for (let i = 0; i < array.length; i++){
        if (array[i] % 2 == 0){
            even_array.push(array[i]);
        }
        else{
            odd_array.push(array[i]);
        }
    }
    even_array.sort((a,b)=>b-a);
    odd_array.sort();
    result = odd_array.concat(even_array);
    return result;

}

console.log(sort_array(array = [3,5,2,9,45,21,34,43,6,12,10,19,30,44,24,50]))