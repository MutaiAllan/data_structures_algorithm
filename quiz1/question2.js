function rotateArray(arr, k) {
    while (k > 0) {
        const temp = arr[0];
        arr.shift();
        arr.push(temp);
        k--;
    }
    return arr;
}

const array = [1, 2, 3, 4, 5];
const k = 2
if (k <= 0) {
    console.log(array);
} else if (k > array.length) {
    k %= array.length;
    console.log(rotateArray(array, k));
} else {
    console.log(rotateArray(array, k));
}
