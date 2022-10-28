function time_output(array){
    for (let i = 0; i < array.length; i++){
        setTimeout(function(){
            console.log(i);
        }, i * 3000);
    }
}
const array = [4,54,76,323,544,21];   

time_output(array);