namespace BookExchange.Models;

public class Book
{
    public int BookId { get; set; }
    public string Title { get; set; }
    public string Genre { get; set; }
    public int OwnerId { get; set; }
    public int AuthorId { get; set; }
}
