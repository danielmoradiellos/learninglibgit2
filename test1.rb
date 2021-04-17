require 'rugged'
repo = Rugged::Repository.new('/home/proprietaire/git/learninglibgit2')
commit = repo.head.target
puts commit.message
puts "#{commit.author[:name]} <#{commit.author[:email]}>"
tree = commit.tree

