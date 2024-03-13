using System;
using UnityEngine;
using UnityEngine.UI;
using Random = UnityEngine.Random;

public class MosaicGenerator : MonoBehaviour
{
    [SerializeField] private InputField widthInputField;
    [SerializeField] private InputField heightInputField;
    [SerializeField] private InputField blocksInputField;
    [SerializeField] private Text errorMassage;
    private Color[] mosaicColors;
    public Texture2D generatedMosaic;
    public Image renderImage;

    private void Start()
    {
        mosaicColors = new Color[3];
        mosaicColors[0] = Color.blue;
        mosaicColors[1] = Color.green;
        mosaicColors[2] = Color.red;
    }

    public void OnGenerate()
    {
        if (!int.TryParse(widthInputField.text, out int mosaicWidth)
            | !int.TryParse(heightInputField.text, out int mosaicHeight)
            | !int.TryParse(blocksInputField.text, out int blocksSize))
        {
            errorMassage.text = "ERROR: Enter valid data!";
            return;
        }

        renderImage.rectTransform.sizeDelta = new Vector2(mosaicWidth, mosaicHeight);
        GenerateMosaic(mosaicWidth, mosaicHeight, blocksSize);
    }
    
    void GenerateMosaic(int mosaicWidth, int mosaicHeight, int blockSize)
    {
        generatedMosaic = new Texture2D(mosaicWidth, mosaicHeight);

        for (int y = 0; y < mosaicHeight; y++)
        {
            for (int x = 0; x < mosaicWidth; x++)
            {
                Color randomColor = mosaicColors[Random.Range(0, mosaicColors.Length)];

                for (int blockY = 0; blockY < blockSize; blockY++)
                {
                    for (int blockX = 0; blockX < blockSize; blockX++)
                    {
                        int pixelX = x * blockSize + blockX;
                        int pixelY = y * blockSize + blockY;

                        generatedMosaic.SetPixel(pixelX, pixelY, randomColor);
                    }
                }
            }
        }

        generatedMosaic.Apply();
        ApplyTextureToMaterial();
    }
    
    void ApplyTextureToMaterial()
    {
        renderImage.enabled = true;
        Material material = renderImage.material;
        material.mainTexture = generatedMosaic;
    }
}
