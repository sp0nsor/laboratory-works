using Microsoft.EntityFrameworkCore;

namespace BookExchange.Models;

public class BookExchangeDbContext: DbContext
{
    public DbSet<Account> Accounts { get; set; }
    public DbSet<Author> Authors { get; set; }
    public DbSet<Book> Books { get; set; }
    // public DbSet<Loan> Loans { get; set; }
    public DbSet<Reader> Readers { get; set; }

    public BookExchangeDbContext(DbContextOptions<BookExchangeDbContext> options) : base(options)
    {
    }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        // modelBuilder.Entity<Account>()
        //     .HasOne(a => a.Reader)
        //     .WithOne(r => r.Account)
        //     .HasForeignKey<Reader>(r => r.AccountId)
        //     .OnDelete(DeleteBehavior.NoAction);
    
        // modelBuilder.Entity<Loan>()
        //     .HasOne(l => l.Account)
        //     .WithMany(a => a.Loans)
        //     .HasForeignKey(l => l.AccountId)
        //     .OnDelete(DeleteBehavior.NoAction);
        //
        // modelBuilder.Entity<Loan>()
        //     .HasOne(l => l.Book)
        //     .WithOne(b => b.Loan)
        //     .HasForeignKey<Book>(b => b.LoanId)
        //     .OnDelete(DeleteBehavior.NoAction);
    
        // modelBuilder.Entity<Book>()
        //     .HasOne(b => b.Reader)
        //     .WithMany(r => r.Books)
        //     .HasForeignKey(b => b.ReaderId)
        //     .OnDelete(DeleteBehavior.NoAction);
        //
        // modelBuilder.Entity<Book>()
        //     .HasOne(b => b.Author)
        //     .WithMany()
        //     .HasForeignKey(b => b.AuthorId)
        //     .OnDelete(DeleteBehavior.NoAction);
    }
}