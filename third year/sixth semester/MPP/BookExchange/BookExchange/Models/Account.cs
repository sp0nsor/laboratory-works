namespace BookExchange.Models;

public class Account
{
    public int AccountId { get; set; }
    public string Email { get; set; }
    public string Password { get; set; }
    public int ReaderId { get; set; }
}
