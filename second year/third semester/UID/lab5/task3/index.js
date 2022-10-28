function unique(){
    let result = [];
    for (let i = 0; i < arguments.length; i++){
        if (!result.includes(arguments[i])){
            result.push(arguments[i]);
        }
    }
    return result;
}

console.log(unique(3,3,123,12,123, "qwe", "qwe", "zxc", "zxc"));