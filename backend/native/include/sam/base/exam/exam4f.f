C-----------------------------------------------------------------------
C                   test and demonstrate random object
C-----------------------------------------------------------------------
      program main
      include 'base/fortran/base.inc'
      integer i
      real f
      double precision random

C                  instance Random object
      call vsyf_RandomBegin (random)

C                  generate and print 10 random numbers 
      write(6,*) "Default seed"
      do i = 0,9
         call vsyf_RandomNumber (random,f)
         write(6,*) "i,f",i,f
      enddo
C                  set a seed and generate 10 more random numbers 
      write(6,*) "User seed"
      call vsyf_RandomInit (random,70946)
      do i = 0,9
         call vsyf_RandomNumber (random,f)
         write(6,*) "i,f",i,f
      enddo
C                  destroy Random object
      call vsyf_RandomEnd (random)
      stop
      end
