function isDup(arr) {
    let found = false;
    let i = 0;
    while (i < arr.length - 1) {
        let j = i + 1;
        while (j < arr.length) {
            if (arr[i] === arr[j]) {
                found = true;
                break;
            }
            j++;
        }
        if (found) {
            break;
        }
        i++;
    }
    return found;
}

const array = [1, 2, 3, 4, 4, 6];
console.log(isDup(array));
