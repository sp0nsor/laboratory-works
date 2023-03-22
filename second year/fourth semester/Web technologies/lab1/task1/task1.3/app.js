var value = 3;
var arr1 = [-1, 2, 2, -9];
var arr2 = [-1, 2, 3, -9, 11];
var arr3 = [-2, -1, 3, 2];
var bool1;
var bool2;
var bool3;
if (arr1.includes(value)) {
    bool1 = true;
}
else {
    bool1 = false;
}
if (arr2.includes(value)) {
    bool2 = true;
}
else {
    bool2 = false;
}
if (arr3.includes(value)) {
    bool3 = true;
}
else {
    bool3 = false;
}
if (bool1 == true && bool2 == true && bool3 == false || bool1 == false && bool2 == true && bool3 == true || bool1 == true && bool2 == false && bool3 == true) {
    console.log(true);
}
else {
    console.log(false);
}
