using BookExchange.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace BookExchange.Controllers;

[Route("api/[controller]")]
[ApiController]
public class BookExchangeController : ControllerBase
{
    private readonly BookExchangeDbContext _context;

    public BookExchangeController(BookExchangeDbContext context)
    {
        _context = context;
    }

    [HttpPut]
    public async Task<IActionResult> ExchangeBooks(int senderReaderId, int receiverReaderId, int senderBookId, 
        int receiverBookId)
    {
        if (senderReaderId <= 0 | receiverReaderId <= 0 | senderBookId <= 0 | receiverBookId <= 0)
            return BadRequest("Invalid input parameters.");

        var senderReader = await _context.Readers.FirstOrDefaultAsync(r => r.ReaderId == senderReaderId);
        var receiverReader = await _context.Readers.FirstOrDefaultAsync(r => r.ReaderId == receiverReaderId);
        var senderBook = await _context.Books.FirstOrDefaultAsync(b => b.BookId == senderBookId);
        var receiverBook = await _context.Books.FirstOrDefaultAsync(b => b.BookId == receiverBookId);

        if (senderReader == null | receiverReader == null | senderBook == null | receiverBook == null)
            return NotFound("Not found book or account");

        senderReader.BookId = receiverBook.BookId;
        receiverReader.BookId = senderBook.BookId;
        receiverBook.OwnerId = senderReader.ReaderId;
        senderBook.OwnerId = receiverReader.ReaderId;
        
        await _context.SaveChangesAsync();

        return Ok("Book exchange successful.");
    }
}
