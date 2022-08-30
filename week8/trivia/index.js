let correct = document.querySelector('.correct');
correct.addEventListener('click', function() {
    correct.style.backgroundColor = 'green';
    document.querySelector('#feedback1').innerHTML = 'Correct!';
});

let incorrects = document.querySelectorAll('.incorrect');
for (let i = 0; i < incorrects.length; i++) {
    incorrects[i].addEventListener('click', function() {
        incorrects[i].style.backgroundColor = 'red';
        document.querySelector('#feedback1').innerHTML = 'incorrect';
    });
}

document.querySelector('#check').addEventListener('click', function() {
    let input = document.querySelector('input');
    if (input.value === 'Berlin' || 'berlin') {
        input.style.backgroundColor = 'green';
        document.querySelector('#feedback2').innerHTML = 'Correct';
    } else {
        input.style.backgroundColor = 'red';
        document.querySelector('#feedback2').innerHTML = 'Incorrect';
    }
});
