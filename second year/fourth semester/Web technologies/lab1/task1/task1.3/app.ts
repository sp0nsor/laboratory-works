function findElements(arr1: any[], arr2: any[], arr3: any[]): any[] {
    const result: any[] = [];
  
    for (let i = 0; i < arr1.length; i++) {
      if ((arr2.indexOf(arr1[i]) > -1 || arr3.indexOf(arr1[i]) > -1) && result.indexOf(arr1[i]) === -1) {
        result.push(arr1[i]);
      }
    }
  
    for (let i = 0; i < arr2.length; i++) {
      if (arr3.indexOf(arr2[i]) > -1 && result.indexOf(arr2[i]) === -1) {
        result.push(arr2[i]);
      }
    }
  
    return result;
  }

  const arr1 = [1, 2, 3, 4];
  const arr2 = [3, 4, 5, 6];
  const arr3 = [4, 6, 7, 8];
  
  const result = findElements(arr1, arr2, arr3);

console.log(result);