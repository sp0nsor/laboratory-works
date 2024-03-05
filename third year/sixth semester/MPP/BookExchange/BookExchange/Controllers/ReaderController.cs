using BookExchange.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace BookExchange.Controllers;

[Route("api/[controller]")]
[ApiController]
public class ReaderController : ControllerBase
{
    private readonly BookExchangeDbContext _context;

    public ReaderController(BookExchangeDbContext context)
    {
        _context = context;
    }

    [HttpGet]
    public async Task<ActionResult<IEnumerable<Reader>>> GetReaders()
    {
        return await _context.Readers.ToListAsync();
    }

    [HttpGet("{id}")]
    public async Task<ActionResult<Reader>> GetReader(int id)
    {
        var reader = await _context.Readers.FindAsync(id);

        if (reader == null)
            return NotFound();

        return reader;
    }

    [HttpPost]
    public async Task<ActionResult<Reader>> PostReader(Reader reader)
    {
        _context.Readers.Add(reader);
        await _context.SaveChangesAsync();

        return CreatedAtAction(nameof(GetReader), new { id = reader.ReaderId }, reader);
    }

    [HttpPut("{id}")]
    public async Task<IActionResult> PutAccount(int id, Reader reader)
    {
        if (id != reader.ReaderId)
            return BadRequest();

        _context.Entry(reader).State = EntityState.Modified;

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateConcurrencyException)
        {
            if (!ReaderExists(id))
                return NotFound();
            else
                throw;
        }

        return NoContent();
    }

    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteReader(int id)
    {
        var reader = await _context.Readers.FindAsync(id);
        if (reader == null)
            return NotFound();

        _context.Readers.Remove(reader);
        await _context.SaveChangesAsync();

        return NoContent();
    }
    
    private bool ReaderExists(int id)
    {
        return _context.Readers.Any(e => e.ReaderId == id);
    }
}