using System;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    [SerializeField] private GameObject inputPanel;
    [SerializeField] private GameObject menuButton;
    [SerializeField] private InputField sizeInputField;
    [SerializeField] private InputField colorInputField;
    [SerializeField] private InputField typeInputField;
    [SerializeField] private Text errorMassage;
    [SerializeField] private GameObject drawObject;
    private Circle circleComponent;
    private Square squareComponent;

    private void Start()
    {
        circleComponent = drawObject.AddComponent<Circle>();
        squareComponent = drawObject.AddComponent<Square>();
    }

    public void OnCreateDraw()
    {
        if (!float.TryParse(sizeInputField.text, out float sizeResult)
            | !IsValidHex(colorInputField.text) |!ColorUtility.TryParseHtmlString(colorInputField.text, out Color color))
        {
            errorMassage.text = "ERROR: enter valid data!";
            return;
        }

        errorMassage.text = ""; 
        DrawImage(typeInputField.text, sizeResult, color);
    }

    private void DrawImage(string typeImage, float sizeValue, Color color)
    {
        switch (typeImage)
        {
                case "Circle":
                circleComponent = drawObject.GetComponent<Circle>();       
                circleComponent.SetRadius(sizeValue);
                circleComponent.Draw(color);
                break;
            case "Square":
                squareComponent = drawObject.GetComponent<Square>();
                squareComponent.SetLength(sizeValue);
                squareComponent.Draw(color);
                break;
        }
    }
    
    public void OnEnableInputPanel()
    {
        inputPanel.SetActive(true);
        menuButton.SetActive(false);
    }

    public void OnDisablePanel()
    {
        inputPanel.SetActive(false);
        menuButton.SetActive(true);
    }

    public void OnCancel()
    {
        Destroy(drawObject.GetComponent<LineRenderer>());
    }
    
    private bool IsValidHex(string hex)
    {
        string hexPattern = @"^#(?:[0-9a-fA-F]{3}){1,2}$";

        return Regex.IsMatch(hex, hexPattern);
    }
}
