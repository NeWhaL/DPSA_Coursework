

const mainForms = document.getElementsByClassName('question')

console.log(mainForms[0][0])
// mainForms[0][0].textContent = 'Правильный ответ на первый вопрос'

document.getElementById('end-button').onclick = () =>
{
  for(let i = 0; i < 2; i++)
    for(let j = 0; j < 4; j++)
      if(mainForms[i][j].checked)
        console.log(mainForms[i][j].value)
}

// const sizeArray = 10
// const arrayAnswers = new Array(sizeArray)
// const arrayAllForms = new Array(sizeArray)

// const getAllForms = (arrayAllForms) => 
// {
//   for(let i = 0; i < arrayAllForms.length; i++)
//     arrayAllForms[i] = document.getElementsByName('question' + String(i + 1))
// }

// const questionForm =
// {
//   question: 'Первый вопрос легкого теста',
//   answer1: 'Первый вариант ответа',
//   answer2: 'Второй вариант ответа',
//   answer3: 'Третий вариант ответа',
//   answer4: 'Четвертый вариант ответа',
// }

// const StartTest = () =>
// {
//   const arrQuestions = new Array(sizeArray)
//   for(let i = 0; i < 1; i++)
//   {
//     const question = { ...questionForm }
//     arrQuestions[i] = question
//   }
//   // const arrayForSendingQuestionsToTheForm = new Array(sizeArray)
//   // getAllForms(arrayForSendingQuestionsToTheForm)
//   const allForm = document.getElementsByClassName('questionsForms')
//   console.log(allForm)
// }

// StartTest()

// const getAllAnswersFromAllForms = () =>
// {
//   for(let i = 0; i < 2; i++)
//     for(let j = 0; j < 4; j++)
//       if(arrayAllForms[i][j].checked)
//         arrayAnswers[i] = arrayAllForms[i][j].value 
// }

// const endTest = () => 
// {
//   getAllForms(arrayAllForms)
//   getAllAnswersFromAllForms()
//   console.log(arrayAnswers)
// }