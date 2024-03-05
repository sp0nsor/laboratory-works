using BookExchange.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace BookExchange.Controllers;

[Route("api/[controller]")]
[ApiController]
public class AuthorController : ControllerBase
{
    private readonly BookExchangeDbContext _context;

    public AuthorController(BookExchangeDbContext context)
    {
        _context = context;
    }

    [HttpGet]
    public async Task<ActionResult<IEnumerable<Author>>> GetAuthors()
    {
        return await _context.Authors.ToListAsync();
    }

    [HttpGet("{id}")]
    public async Task<ActionResult<Author>> GetAuthor(int id)
    {
        var author = await _context.Authors.FindAsync(id);

        if (author == null)
            return NotFound();

        return author;
    }

    [HttpPost]
    public async Task<ActionResult<Author>> PostAuthor(Author author)
    {
        _context.Authors.Add(author);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetAuthor), new { id = author.AuthorId }, author);
    }

    [HttpPut("{id}")]
    public async Task<IActionResult> PutAuthor(int id, Author author)
    {
        if (id != author.AuthorId)
            return BadRequest();

        _context.Entry(author).State = EntityState.Modified;

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateConcurrencyException)
        {
            if (!AuthorExists(id))
                return NotFound();
            else
                throw;
        }

        return NoContent();
    }

    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteAuthor(int id)
    {
        var author = await _context.Authors.FindAsync(id);
        if (author == null)
            return NotFound();

        _context.Authors.Remove(author);
        await _context.SaveChangesAsync();

        return NoContent();
    }
    
    private bool AuthorExists(int id)
    {
        return _context.Authors.Any(e => e.AuthorId == id);
    }
}