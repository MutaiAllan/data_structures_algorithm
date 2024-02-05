function removeDuplicates(arr) {
    return [...new Set(arr)];
}

const numbers = [4, 9, 3, 4, 0, 5, 1, 6, 7, 8, 8, 5, 9];
console.log(numbers);
const uniqueNumbers = removeDuplicates(numbers);
console.log(uniqueNumbers);