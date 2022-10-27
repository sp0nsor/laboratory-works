function string_comparison(str1, str2){
    let n1 = str1.length;
    let n2 = str2.length;
    letters_str1 = [];
    letters_str2 = [];
    if (n1 != n2){
        console.log(false);
        return false;
    }
    for (let i in str1){
        letters_str1.push(str1[i]);
    }
    for (let i in str2){
        letters_str2.push(str2[i]);
    }
    letters_str1.sort();
    letters_str2.sort();
    for (let i in letters_str1){
        if(letters_str1[i] == letters_str2[i]){
            console.log(true);
            return true;
        }
        else{
            console.log(false);
            return false;
        }
    }

}
let str1 = "hello";
let str2 = "olleh";

string_comparison(str1, str2)