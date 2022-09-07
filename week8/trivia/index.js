let correctAnswer = document.querySelector('.correct');
correctAnswer.addEventListener('click', function() {
    correctAnswer.style.backgroundColor = 'green';
    document.querySelector('#feedback1').innerHTML = 'Correct!';
});

let incorrectAnswers = document.querySelectorAll('.incorrect');
incorrectAnswers.forEach((incorrectAnswer) => {
    incorrectAnswer.addEventListener('click', function() {
        incorrectAnswer.style.backgroundColor = 'red';
        document.querySelector('#feedback1').innerHTML = 'incorrect';
    });
})


document.querySelector('#check').addEventListener('click', function() {
    let input = document.querySelector('input');
    if (input.value.toLowerCase() === 'berlin') {
        input.style.backgroundColor = 'green';
        document.querySelector('#feedback2').innerHTML = 'Correct';
    } else {
        input.style.backgroundColor = 'red';
        document.querySelector('#feedback2').innerHTML = 'Incorrect';
    }
});
