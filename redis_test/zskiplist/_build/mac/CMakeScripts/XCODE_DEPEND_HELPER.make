# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.zskiplist.Debug:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/Debug/zskiplist:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/Debug/zskiplist


PostBuild.zskiplist.Release:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/Release/zskiplist:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/Release/zskiplist


PostBuild.zskiplist.MinSizeRel:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/MinSizeRel/zskiplist:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/MinSizeRel/zskiplist


PostBuild.zskiplist.RelWithDebInfo:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/RelWithDebInfo/zskiplist:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/zskiplist/_build/mac/RelWithDebInfo/zskiplist




# For each target create a dummy ruleso the target does not have to exist
