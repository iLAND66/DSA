fn main() {
    let arr = vec![1, 2, 3, 4, 5];
    let mayor = masGrande(&arr);
    println!("El valor mayor es: {}", mayor)
}

fn masGrande(arr: &[i32]) -> i32 {
    let mut mayor = arr[0];
    for &num in arr.iter() {
        if num > mayor {
            mayor = num;
        }
    }
    mayor
}
