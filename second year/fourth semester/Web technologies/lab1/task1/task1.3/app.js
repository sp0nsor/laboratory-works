function findElements(arr1, arr2, arr3) {
    var result = [];
    for (var i = 0; i < arr1.length; i++) {
        if ((arr2.indexOf(arr1[i]) > -1 || arr3.indexOf(arr1[i]) > -1) && result.indexOf(arr1[i]) === -1) {
            result.push(arr1[i]);
        }
    }
    for (var i = 0; i < arr2.length; i++) {
        if (arr3.indexOf(arr2[i]) > -1 && result.indexOf(arr2[i]) === -1) {
            result.push(arr2[i]);
        }
    }
    return result;
}
var arr1 = [1, 2, 3, 4];
var arr2 = [3, 4, 5, 6];
var arr3 = [4, 6, 7, 8];
var result = findElements(arr1, arr2, arr3);
console.log(result);
