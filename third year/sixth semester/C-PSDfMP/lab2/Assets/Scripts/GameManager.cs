using UnityEngine;
using UnityEngine.UI;
using Random = UnityEngine.Random;

public class GameManager : MonoBehaviour
{
    [SerializeField] private InputField numberInputField;
    [SerializeField] private Text textInfo;
    [SerializeField] private Text errorMassage;
    [SerializeField] private int _currentNumber;

    private void Start()
    {
        _currentNumber = Random.Range(0, 100);
    }

    public void OnSendButton()
    {
        errorMassage.text = "";
        if (!int.TryParse(numberInputField.text, out int inputNumber))
        {
            errorMassage.text = "ERROR: Enter valid data!";
            return;
        }

        if (inputNumber == _currentNumber)
        {
            textInfo.text = "You won! Enter new number.";
            _currentNumber = Random.Range(0, 100);
            return;
        }

        textInfo.text = inputNumber < _currentNumber ? "Your number < current number." : "Your number > current number.";
    }
}
