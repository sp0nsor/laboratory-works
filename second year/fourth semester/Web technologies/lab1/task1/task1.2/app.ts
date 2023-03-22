let list: number[] = [1, 0, -4, 5, 6, -7,-2, 3, 8];
let sum: number = 0;
let maxSum: number = 0;
list.forEach((element)=>{
    sum += element;
    maxSum = Math.max(maxSum, sum);
    if (sum < 0){
        sum = 0;
    }
})
console.log(maxSum);