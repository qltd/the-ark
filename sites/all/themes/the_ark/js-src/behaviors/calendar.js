function twoDigit (num) {
  return ('0' + num).slice(-2);
}

(function ($) {
  Drupal.behaviors.theArkCalendar = {
    attach: function () {
      var container = $('.calendar-body');
      if (container.length === 0) return;

      var today = new Date();
      var formattedDate = today.getFullYear() + '-' + twoDigit(today.getMonth() + 1) + '-' + twoDigit(today.getDate());
      var dateMatch = $('[data-date="' + formattedDate + '"]');
      var mediaQuery = window.matchMedia ? window.matchMedia('all and (max-width: 1025px)') : { matches: false };

      if (mediaQuery.matches && dateMatch.length && dateMatch.hasClass('calendar-column-current-month')) {
        setTimeout(function () {
          $('html, body').animate({
            scrollTop: dateMatch.offset().top
          }, 500);
        }, 100);  
      }
    }
  };
})(jQuery);
