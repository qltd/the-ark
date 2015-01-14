(function ($) {

  function togglePastEventsText (action) {
    return 'Click to ' + action + ' Past Events';
  }

  var monthNames = [
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
    'July',
    'August',
    'September',
    'October',
    'November',
    'December'
  ];

  Drupal.behaviors.theArkCalendar = {
    attach: function () {
      var container = $('.calendar-body');
      if (container.length === 0) return;

      var dateNav = $('.date-nav').clone();
      dateNav.children('.date-heading').remove();
      container.append(dateNav);

      var today = container.find('.today');
      if (today.length === 0) return;

      var past = container.find('.past');
      if (past.length === 0) return;

      var toggleContainer = $('<div class="show-past-toggle-container"></div>')
        , toggle = $('<a class="show-past-toggle" role="button"></div>');

      toggle.text(togglePastEventsText('Show'));
      toggleContainer.append(toggle);
      container.prepend(toggleContainer);
      past.addClass('past-hidden');

      toggle.on('tap', function () {
        if (past.hasClass('past-hidden')) {
          past.removeClass('past-hidden');
          toggle.text(togglePastEventsText('Hide'));
        } else {
          past.addClass('past-hidden');
          toggle.text(togglePastEventsText('Show'));
        }
      });
    }
  };
})(jQuery);
