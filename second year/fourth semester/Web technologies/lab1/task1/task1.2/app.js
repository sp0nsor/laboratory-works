var list = [1, 0, -4, 5, 6, -7, -2, 3, 8];
var sum = 0;
var maxSum = 0;
list.forEach(function (element) {
    sum += element;
    maxSum = Math.max(maxSum, sum);
    if (sum < 0) {
        sum = 0;
    }
});
console.log(maxSum);
