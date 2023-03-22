let value: number = 3;
let arr1: number[] = [-1, 2, 3, -9];
let arr2: number[] = [-1, 2, 3, -9, 11];
let arr3: number[] = [-2, -1, 1, 2];
let bool1: boolean;
let bool2: boolean;
let bool3: boolean;

if (arr1.includes(value)){
    bool1 = true;
}
else{
    bool1 = false;
}
if (arr2.includes(value)){
    bool2 = true;
}
else{
    bool2 = false;
}

if (arr3.includes(value)){
    bool3 = true;
}
else{
    bool3 = false;
}
if(bool1 == true && bool2 == true && bool3 == false || bool1 == false && bool2 == true && bool3 == true || bool1 == true && bool2 == false && bool3 == true){
    console.log(true);
}
else{
    console.log(false);
}