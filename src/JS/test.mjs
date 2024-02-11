//document.querySelector('button').onclick = function() { alert('Кнопка нажата') }

/*const allInput = [...document.querySelectorAll('input')]
allInput.forEach((element) => {console.log(element.value)})

const maxAmountTrueAnswers = 10
let countTrueAnswers = 0
const endTest = () =>
{
  
}*/
const sizeArray = 10
const arrayAnswers = new Array(sizeArray)
const arrayAllForms = new Array(sizeArray)

const getAllForms = () => 
{
  for(let i = 0; i < arrayAllForms.length; i++)
    arrayAllForms[i] = document.getElementsByName('question' + String(i + 1))
}

const getAllAnswersFromAllForms = () =>
{
  for(let i = 0; i < 2; i++)
    for(let j = 0; j < 4; j++)
      if(arrayAllForms[i][j].checked)
        arrayAnswers[i] = arrayAllForms[i][j].value 
}

const endTest = () => 
{
  getAllForms()
  getAllAnswersFromAllForms()
  console.log(arrayAnswers)
}

//Получене значения отверта на определенный вопрос
//const allForms = document.getElementsByName('question1')